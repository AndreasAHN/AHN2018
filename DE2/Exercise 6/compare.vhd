library ieee;
use ieee.std_logic_1164.all;

entity compare is
port(
	tm_watch : in	std_logic_vector(15 downto 0);
	tm_alarm : in	std_logic_vector(15 downto 0);
	alarm 	: out	std_logic
);
end compare;

architecture behavirual of compare is
begin
	comp : process(tm_watch, tm_alarm)
	begin
		if tm_alarm = tm_watch then
			alarm <= '1';
		else
			alarm <= '0';
		end if;
	end process;
end behavirual;