-------- guess_game_tester --------
library ieee;
use ieee.std_logic_1164.all;

entity guess_game_tester is
	port(
			KEY : in std_logic_vector(3 downto 0); 
			SW : in std_logic_vector(7 downto 0);
			HEX0 : out std_logic_vector(6 downto 0);
			HEX1 : out std_logic_vector(6 downto 0);
			HEX2 : out std_logic_vector(6 downto 0);
			HEX3 : out std_logic_vector(6 downto 0);
			HEX4 : out std_logic_vector(6 downto 0);
			HEX5 : out std_logic_vector(6 downto 0);
			HEX6 : out std_logic_vector(6 downto 0);
			HEX7 : out std_logic_vector(6 downto 0)
			);			
end guess_game_tester;

architecture structure of guess_game_tester is

	signal	player   :	std_logic;
	signal	Display1 :	std_logic_vector(6 downto 0);
	signal	Display2 :	std_logic_vector(6 downto 0);
	signal	Display3 :	std_logic_vector(6 downto 0);
	signal	Display4 :	std_logic_vector(6 downto 0);
	signal	Knap1 :	std_logic_vector(2 downto 0);
	signal	Knap2 :	std_logic_vector(2 downto 0);		

begin
	playerMUX: process(key(3), player)
	begin		
		if player = '0' then
				Knap1(2 downto 0) <= key(2 downto 0);
		else
				Knap2(2 downto 0) <= key(2 downto 0);
		end if;
		
		if key(3) = '0' then
			if player = '1' then
				player <= '0';
			else
				player <= '1';
			end if;
		end if;
	end process playerMUX;
	
		Player1: entity work.guess_game port map(
			inputs => SW(7 downto 0),
			set => Knap1(0),
			show => Knap1(1),
			try => Knap1(2),
			display4OUT => Display1,
			display5OUT => Display2
															);
						
		Player2: entity work.guess_game port map(
			inputs => SW(7 downto 0),
			set => Knap2(0),
			show => Knap2(1),
			try => Knap2(2),
			display4OUT => Display3,
			display5OUT => Display4
															);							
	
		HEX4 <= "0100100" when (player = '0') else
		"1111001" when (player = '1');
		
		HEX0 <= Display1 	when (player = '0') else
		Display3 when (player = '1');
		
		HEX1 <= Display2 when (player = '0') else
		Display4 when (player = '1');
	
	HEX2 <= "1111111";
	HEX3 <= "1111111";
	HEX5 <= "1111111";
	HEX6 <= "1111111";
	HEX7 <= "1111111";
end structure; 




