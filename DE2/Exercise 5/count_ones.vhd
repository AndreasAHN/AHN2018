library ieee;
use ieee.std_logic_1164.all;

entity count_ones is
port(
	sw		:	in		std_logic_vector(7 downto 0);
	hex0	:	out	std_logic_vector(6 downto 0)
	);
end count_ones;

architecture combinational of count_ones is 
signal binary : std_logic_vector(3 downto 0);
begin
	p1: 		entity work.process_with_loop port map(a => sw, ones => binary);
	bin2hex: entity work.sevenseg_decoder	port map(bin => binary, seg => hex0);
end combinational;