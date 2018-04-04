library ieee;
use ieee.std_logic_1164.all;

entity multi_counter_tester is
port(
	KEY	:	in		std_logic_vector(3 downto 0);
	SW		:	in		std_logic_vector(17 downto 16);
	HEX0	:	out	std_logic_vector(6 downto 0);
	LEDR	:	out	std_logic_vector(0 downto 0)
);
end multi_counter_tester;

architecture structural of multi_counter_tester is
signal binc : std_logic_vector(3 downto 0);
begin
	mtc: entity work.multi_counter 		port map(clk => KEY(0), mode => SW, reset => 
																KEY(3), count => binc, cout => LEDR(0));
	b2h: entity work.sevenseg_decoder 	port map(bin => binc, seg => HEX0);
end structural;