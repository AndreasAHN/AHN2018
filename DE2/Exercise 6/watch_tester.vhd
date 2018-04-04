library ieee;
use ieee.std_logic_1164.all;

entity watch_tester is
port(
	HEX2 		: out std_logic_vector(6 downto 0);
	HEX3 		: out std_logic_vector(6 downto 0);
	HEX4 		: out std_logic_vector(6 downto 0);
	HEX5 		: out std_logic_vector(6 downto 0);
	HEX6 		: out std_logic_vector(6 downto 0);
	HEX7 		: out std_logic_vector(6 downto 0);
	CLOCK_50 : 	in std_logic;
	KEY		: in std_logic_vector(3 downto 0)
);
end watch_tester;

architecture structural of watch_tester is
begin
	wtch1: entity work.watch port map (
	clk=>CLOCK_50, speed => key(0), 
	reset => key(3), sec_1 => hex2,
	sec_10 => hex3, min_1 => hex4,
	min_10 => hex5, hrs_1 => hex6,
	hrs_10 => hex7);
end structural;