library ieee;
use ieee.std_logic_1164.all;

entity sevenseg_decoder_tester is
port(
	sw : in std_logic_vector(3 downto 0);
	HEX0 : out std_logic_vector(6 downto 0)
);
end sevenseg_decoder_tester;

architecture structural of sevenseg_decoder_tester is
begin
	bin2hex: entity work.sevenseg_decoder port map(bin => sw, seg => HEX0);
end structural;