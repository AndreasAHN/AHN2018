library ieee;
use ieee.std_logic_1164.all;

entity reset_logic is
port(
	reset_in : in std_logic;
	reset_out :  out std_logic;
	hours_bin1 : in std_logic_vector(3 downto 0);
	hours_bin10: in std_logic_vector(3 downto 0)
);

end reset_logic;

architecture behavirual of reset_logic is
begin
	reset : process(reset_in, hours_bin1, hours_bin10)
	begin
		reset_out <= '1';
		if reset_in = '0' then
			reset_out <= '0';
		elsif hours_bin1 = "0100" and hours_bin10 = "0010" then
			reset_out <= '0';
		else
			reset_out <= '1';
		end if;
	end process;
end behavirual;