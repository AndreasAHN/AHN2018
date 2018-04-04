library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity multi_counter is
port(
	clk 	:	in 	std_logic;
	mode 	: 	in 	std_logic_vector(1 downto 0);
	reset	:	in 	std_logic;
	count	:	out	std_logic_vector(3 downto 0);
	cout 	:	out 	std_logic
	);
end multi_counter;


architecture behavioral of multi_counter is
signal p_count : unsigned(3 downto 0);
signal p_cout : std_logic;
begin
	counter: process(clk, reset)
	begin	
		if	reset = '0' then
			p_count <= "0000";
		elsif clk = '1' and clk'event then
			if	mode = "00" then
				if	p_count < "1001" then
					p_count <= p_count + 1;
					p_cout <= '0';
				else
					p_count <= "0000";
					p_cout <= '1';
				end if;
			elsif mode = "10" or mode = "11" then
				if	p_count < "0010" then
					p_count <= p_count + 1;
					p_cout <= '0';
				else
					p_count <= "0000";
					p_cout <= '1';
				end if;
			elsif mode = "01" then
				if	p_count < "0101" then
					p_count <= p_count + 1;
					p_cout <= '0';
				else
					p_count <= "0000";
					p_cout <= '1';
				end if;
			end if;
		end if;
	end process;
	count <= std_logic_vector(p_count);
	cout <= p_cout;
end behavioral;