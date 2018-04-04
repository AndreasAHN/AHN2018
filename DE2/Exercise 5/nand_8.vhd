library ieee;
use ieee.std_logic_1164.all;

entity nand_8 is
port(
	a : in	std_logic_vector(7 downto 0);
	y : out 	std_logic
);
end nand_8;

architecture combinational of nand_8 is
begin 
	pnand8: process(a)
	variable odd : std_logic;
	begin
		odd := '0';
		for index in 7 downto 0 loop
			odd := odd nand a(index);
		end loop;
		y <= odd;
	end process pnand8;
end combinational;