library ieee;
use ieee.std_logic_1164.all;

entity input_limiter is
port(
	bin_min1, bin_min10, bin_hrs1, bin_hrs10 	: in std_logic_vector(3 downto 0);
	time_alarm											: out std_logic_vector(15 downto 0)
);
end input_limiter;

architecture dataflow of input_limiter is
begin
	time_alarm(3 downto 0) <=bin_min1;
	time_alarm(7 downto 4) <= bin_min10;
	time_alarm(11 downto 8) <= bin_hrs1;
	time_alarm(15 downto 12) <=bin_hrs10;
end dataflow;