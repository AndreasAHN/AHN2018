-------- tester --------
library ieee;
use ieee.std_logic_1164.all;

entity code_lock_tester is
	port(
			KEY : in std_logic_vector(3 downto 2); 
			SW : in std_logic_vector(7 downto 0);
			LEDG : out std_logic_vector(1 downto 0);
			CLOCK_50 : in std_logic;
			LEDR : out std_logic_vector(7 downto 0);
			GPIO_0: out std_logic_vector(1 downto 0);
			HEX0: out std_logic_vector(6 downto 0);
			HEX1: out std_logic_vector(6 downto 0);
			HEX2 : out std_logic_vector(6 downto 0);
			HEX3 : out std_logic_vector(6 downto 0);
			HEX4 : out std_logic_vector(6 downto 0);
			HEX5 : out std_logic_vector(6 downto 0);
			HEX6 : out std_logic_vector(6 downto 0);
			HEX7 : out std_logic_vector(6 downto 0)
			);			
end code_lock_tester;

architecture structure of code_lock_tester is	
 signal	LYS   :	std_logic;
 signal nu : std_logic_vector(5 downto 0);
 signal display1 : std_logic_vector(6 downto 0);
 signal display2 : std_logic_vector(6 downto 0);
begin

		code_lock_tester: entity work.code_lock port map(
			code => SW(7 downto 0),
			clk => CLOCK_50,
			reset => key(2),
			enter => key(3),
			lock	 => LYS
			
										);
		LEDG(0) <= LYS;
		GPIO_0(0) <= LYS;
		LEDR <= SW(7 downto 0);
		
		show1: entity work.sevenseg_decoder port map(bin => SW(3 downto 0), seg => display1);
		show2: entity work.sevenseg_decoder port map(bin => SW(7 downto 4), seg => display2);

		HEX0 <= display1;
		HEX1 <= display2;
		HEX2 <= "1111111";
		HEX3 <= "1111111";
		HEX4 <= "1111111";
		HEX5 <= "1111111";
		HEX6 <= "1111111";
		HEX7 <= "1111111";
		
		end structure; 




