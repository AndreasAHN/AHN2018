library ieee;
use ieee.std_logic_1164.all;

entity one_digit_clock_tester is
port(
	CLOCK_50 : 	in 	std_logic;
	KEY		:	in		std_logic_vector(3 downto 0);
	SW			:	in		std_logic_vector(17 downto 16);
	HEX0		:	out	std_logic_vector(6 downto 0);
	LEDR		:	out	std_logic_vector(0 downto 0)
);
end one_digit_clock_tester;

architecture structural of one_digit_clock_tester is
signal binc : std_logic_vector(3 downto 0);
signal clkc : std_logic;
begin
	cg:  entity work.clock_gen 			port map(clk => CLOCK_50, speed =>KEY(0), reset => KEY(3), clk_out => clkc);
	mtc: entity work.multi_counter 		port map(clk => clkc, mode => SW, reset => KEY(3), count => binc, cout => LEDR(0));
	b2h: entity work.sevenseg_decoder 	port map(bin => binc, seg => HEX0);
end structural;