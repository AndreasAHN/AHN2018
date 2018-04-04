-------- guess_game_tester --------
library ieee;
use ieee.std_logic_1164.all;

entity guess_game_tester is
	port(
			KEY : in std_logic_vector(2 downto 0); 
			SW : in std_logic_vector(7 downto 0);
			HEX0 : out std_logic_vector(6 downto 0);
			HEX1 : out std_logic_vector(6 downto 0)
			);			
end guess_game_tester;

architecture structure of guess_game_tester is

	signal	lager :	std_logic_vector(7 downto 0);

begin
	Test: entity work.guess_game port map(
		inputs => SW(7 downto 0),
		set => key(0),
		show => key(1),
		try => key(2),
		display4OUT => HEX0,
		display5OUT => HEX1
														);
end structure; 




