-------- code_lock --------
library ieee;
use ieee.std_logic_1164.all;

entity code_lock is
	port( code: in std_logic_vector(7 downto 0);
			reset: in std_logic;
			enter: in std_logic;
			clk: in std_logic;
			lock: out std_logic;
			status: out std_logic_vector(5 downto 0));
end code_lock;

architecture code_lock_build of code_lock is

	 signal	code1   :	std_logic_vector(7 downto 0);

type state is (Idle, Evaluating_Code_1, Unlocked, Going_Idle);
signal present_state, next_state : state;

begin
	code1 <= "01111011";

state_reg: process(clk, reset)
begin
	if reset = '0' then
		present_state <= idle;
	elsif rising_edge(clk) then
		present_state <= next_state;
	end if;
end process;

nxt_state: process (present_state, enter, code, code1
)	--state machine process.
begin
	next_state <=  present_state;

	case present_state is
		when Idle =>					----Første State Idle
			if enter = '0' then
				next_state <= Evaluating_Code_1;
			end if;
			
		when Evaluating_Code_1 =>					------Anden State Evaluating_Code_1
			if enter = '1' AND code = code1 then
				next_state <= Unlocked;
			elsif enter = '1' AND code /= code1 then
				next_state <= Idle;
			end if;
			
		when Unlocked =>							-------- Femte state Unlocked
			if enter = '0' then
				next_state <= Going_Idle;
			end if;
			
		when Going_Idle =>						------- Sjete state Going_Idle
			if enter = '1' then
				next_state <= Idle;
			end if;
			
		when others =>
				next_state <= Idle;
		
	end case;
end process;

outputs: process (present_state)	--state machine process.
begin
	case present_state is
		when Idle =>									----Første State Idle
				lock <= '0';

			
		when Evaluating_Code_1 =>					------Anden State Evaluating_Code_1
				lock <= '0';

			
			
		when Unlocked =>							-------- Femte state Unlocked
				lock <= '1';

			
		when Going_Idle =>						------- Sjete state Going_Idle
				lock <= '0';

				
		when others =>
				lock <= '0';


		
	end case;
end process;


end code_lock_build;
