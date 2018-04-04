library ieee;
use ieee.std_logic_1164.all;

entity half_adder_behavioral is
	port (a,b : in std_logic;
	sum, carry_out : out std_logic);
end half_adder_behavioral;

architecture behavior of half_adder_behavioral is
begin
	ha:process (a,b)
	begin	if a = '1' then
		sum <= not b;
		carry_out <= b;
	else
		sum <= b;
		carry_out <= '0';
		end if;
	end process ha;

end behavior;