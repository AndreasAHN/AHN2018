library ieee;
use ieee.std_logic_1164.all;

entity alarm_watch_tester is
port(
	sw 		: in 	std_logic_vector(15 downto 0);
	key		: in	std_logic_vector(3 downto 0);
	clock_50	: in	std_logic;
	hex2,hex3,hex4,hex5,hex6,hex7 : out std_logic_vector(6 downto 0);
	ledr		: out std_logic_vector(0 downto 0)
);
end alarm_watch_tester;

architecture combinatorial of alarm_watch_tester is
signal alarm_time 	: std_logic_vector(15 downto 0); -- bin output of in_lim
signal ttm				: std_logic_vector(15 downto 0); -- compare with alarm_time
signal alarm_ssegs 	: std_logic_vector(27 downto 0); -- output for bin2sseg
signal watch_ssegs	: std_logic_vector(41 downto 0);
signal sseg 			: std_logic_vector(41 downto 0); -- for hex2-7

begin
				-- 	input limiter	--
	in_lim: 	entity work.input_limiter port map(
		bin_min1 => sw(3 downto 0), bin_min10 => sw(7 downto 4),
		bin_hrs1 => sw(11 downto 8), bin_hrs10 => sw(15 downto 12), 
		time_alarm => alarm_time);
				-- sevenseg_decoders	--
	min_1:	entity work.sevenseg_decoder port map(
		bin => alarm_time(3 downto 0), seg => alarm_ssegs(6 downto 0));
	min_10:	entity work.sevenseg_decoder port map(
		bin => alarm_time(7 downto 4), seg => alarm_ssegs(13 downto 7));
	hrs_1:	entity work.sevenseg_decoder port map(
		bin => alarm_time(11 downto 8), seg => alarm_ssegs(20 downto 14));
	hrs_10:	entity work.sevenseg_decoder port map(
		bin => alarm_time(15 downto 12), seg => alarm_ssegs(27 downto 21));
						--	watch	--
	wtch:		entity work.watch	port map(
		clk=>clock_50, speed => key(0),reset=>key(3), tm => ttm,
		sec_1 => watch_ssegs(6 downto 0),	sec_10 => watch_ssegs(13 downto 7), 
		min_1 => watch_ssegs(20 downto 14), min_10 => watch_ssegs(27 downto 21), 
		hrs_1 => watch_ssegs(34 downto 28), hrs_10 => watch_ssegs(41 downto 35));
				--compare alarm with tm --
	comp:		entity work.compare port map(
		tm_watch => ttm, tm_alarm => alarm_time, alarm => ledr(0));
				-- mux to select output --
	sseg <= alarm_ssegs & "11111111111111" when key(2) = '0' else
				watch_ssegs							when key(2) = '1';
					--segment output --
	hex2 <= sseg(6 downto 0);
	hex3 <= sseg(13 downto 7);
	hex4 <= sseg(20 downto 14);
	hex5 <= sseg(27 downto 21);
	hex6 <= sseg(34 downto 28);
	hex7 <= sseg(41 downto 35);
end combinatorial;