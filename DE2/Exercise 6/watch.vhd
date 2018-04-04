library ieee;
use ieee.std_logic_1164.all;

entity watch is
port(
	---in 	mode					: std_logic_vector(1 downto 0);
	clk, speed, reset : in 	std_logic;
	sec_1			 		: out std_logic_vector(6 downto 0);
	sec_10				: out std_logic_vector(6 downto 0);
	min_1					: out std_logic_vector(6 downto 0);
	min_10				: out std_logic_vector(6 downto 0);
	hrs_1					: out std_logic_vector(6 downto 0);
	tm						: out std_logic_vector(15 downto 0);
	hrs_10				: out std_logic_vector(6 downto 0)
);
end watch;


architecture structural of watch is
signal cout : std_logic_vector(5 downto 0);
signal binc : std_logic_vector(23 downto 0);
signal clkc : std_logic;
signal reset_out : std_logic;
begin
									--- clock_gen ---
	cg:   entity work.clock_gen 			port map(clk => clk, speed =>speed, reset => reset_out, clk_out => clkc);
									--- seconds   ---
	mtc1: entity work.multi_counter 		port map(clk => clkc, mode => "00", reset => reset_out, 
																count => binc(3 downto 0), cout => cout(0));
	mtc2: entity work.multi_counter 		port map(clk => cout(0), mode => "01", reset => reset_out, 
																count => binc(7 downto 4), cout => cout(1));
	b2h1: entity work.sevenseg_decoder 	port map(bin => binc(3 downto 0), seg => sec_1);
	b2h2: entity work.sevenseg_decoder 	port map(bin => binc(7 downto 4), seg => sec_10);							
									--- minutes   ---
	mtc3: entity work.multi_counter 		port map(clk => cout(1), mode => "00", reset => reset_out, 
																count => binc(11 downto 8), cout => cout(2));
	mtc4: entity work.multi_counter 		port map(clk => cout(2), mode => "01", reset => reset_out, 
																count => binc(15 downto 12), cout => cout(3));
	b2h3: entity work.sevenseg_decoder 	port map(bin => binc(11 downto 8), seg => min_1);
	b2h4: entity work.sevenseg_decoder 	port map(bin => binc(15 downto 12), seg => min_10);
									--- hours     ---
	mtc5: entity work.multi_counter 		port map(clk => cout(3), mode => "00", reset => reset_out, 
																count => binc(19 downto 16), cout => cout(4));
	mtc6: entity work.multi_counter 		port map(clk => cout(4), mode => "11", reset => reset_out, 
																count => binc(23 downto 20), cout => cout(5));
	b2h5: entity work.sevenseg_decoder 	port map(bin => binc(19 downto 16), seg => hrs_1);
	b2h6: entity work.sevenseg_decoder 	port map(bin => binc(23 downto 20), seg => hrs_10);
									--- reset     ---
	rs:   entity work.reset_logic			port map(reset_in => reset, hours_bin1 => binc(19 downto 16), 
																hours_bin10 => binc(23 downto 20), reset_out => reset_out );
	tm <= binc(23 downto 8);
end structural;