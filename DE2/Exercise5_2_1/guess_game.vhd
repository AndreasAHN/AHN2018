-------- guess_game --------
library ieee;
use ieee.std_logic_1164.all;

entity guess_game is
	port(inputs : in std_logic_vector(7 downto 0);
			set : in std_logic; -- Set predefined value
			show : in std_logic; -- Show predefined value
			try : in std_logic; -- Evaluate guess
			display4OUT : out std_logic_vector(6 downto 0);
			display5OUT : out std_logic_vector(6 downto 0)
			);
end guess_game;

architecture structure of guess_game is
signal secret_number	:	std_logic_vector(7 downto 0);
signal display			:	std_logic_vector(7 downto 0);
signal display0OUT		:	std_logic_vector(6 downto 0);
signal display1OUT		:	std_logic_vector(6 downto 0);
signal display2OUT		:	std_logic_vector(6 downto 0);
signal display3OUT		:	std_logic_vector(6 downto 0);
signal status		:	std_logic;

begin

test_if: process(set, show, try)
begin

	if set = '0' then
		secret_number <= inputs;
		display <= inputs;
	elsif show = '0' then
		display <= secret_number;
	elsif try = '0' then
		if secret_number > inputs then
			display1OUT <= "0001001";
			display0OUT <= "1101111";
		elsif secret_number < inputs then
			display1OUT <= "1000111";
			display0OUT <= "1000000";
		else
			display1OUT <= "0111111";
			display0OUT <= "0111111";
		end if;
			status <= '0';
	else
		status <= '1';
		display <= "00000000";
	end if;
end process test_if;
		
		show1: entity work.sevenseg_decoder port map(bin => display(3 downto 0), seg => display2OUT);
		show2: entity work.sevenseg_decoder port map(bin => display(7 downto 4), seg => display3OUT);
	
	display4OUT <= 	display0OUT when (status = '0') else
							display2OUT;
				
	display5OUT <= 	display1OUT when (status = '0') else
							display3OUT;
	
end structure; 




