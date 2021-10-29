library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Clock1hz is
 PORT(
      clock: IN STD_LOGIC;
		genericfreq: in integer range 0 to 12_500_000;
		newclock: out std_logic
		);
end Clock1hz;

architecture Behavioral of Clock1hz is
   signal soma: integer :=0;
   signal nclock: std_logic := '0';

begin
    newclock <= nclock;
	
	process(clock)
	begin
		if rising_edge(clock) then
			soma <= soma+1;
				if (soma=genericfreq) then
					nclock <= not nclock;
					soma <=0;
				end if;
			end if;
	end process;
	
end Behavioral;

