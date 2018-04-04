library ieee;
use ieee.std_logic_1164.all;

entity clock_gen is
port(
	clk, speed, reset	:	in		std_logic;
	clk_out				:	out	std_logic
);
end clock_gen;

architecture behavioral of clock_gen is
signal clock : std_logic;
begin
	cpu: process(clk, reset)
		variable count : integer;
	begin
		if	reset = '0' then
			clock <= '0';
			count := 0;
		elsif clk = '1' and clk'event then
			if speed = '1' then
				if	count = 50000000 OR count > 50000000 then
					clock <= '1';
					count := 0;
				else
					clock <= '0';
					count := count + 1;
				end if;
			elsif speed = '0' then
				if	count = 250000 OR count > 250000 then
					clock <= '1';
					count := 0;
				else
					clock <= '0';
					count := count + 1;
				end if;
			end if;
		end if;
	end process;
	clk_out <= clock;
end behavioral;
