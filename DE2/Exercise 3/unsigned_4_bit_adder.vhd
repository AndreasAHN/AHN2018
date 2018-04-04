----------------- 4-bit unsigned adder -----------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all

entity unsigned_4_bit_adder is
	port(
		ledr	:	out	std_logic_vector(4 downto 1);
		sw		:	in		std_logic_vector(8 downto 1)
	);
end unsigned_4_bit_adder;

architecture unsigned_impl of unsigned_4_bit_adder is
component unsigned_4bit
	port(	A,B	:	in 	std_logic_vector(4 downto 1);
			Sum	:	out	std_logic_vector(4 downto 1));
end component;

signal sum1, sum2	:	std_logic_vector;
begin
	f1	:	unsigned_4bit port map	(A <= unsigned(sw(8 downto 5)));
	f2	:	unsigned_4bit port map	(B <= unsigned(sw(8 downto 5)));
	f3	:	unsigned_4bit port map	(Sum <= A+B);
	f4	:	unsigned_4bit port map	(ledr <= std_logic_vector(Sum));
end unsigned_4bit;