library ieee;
use ieee.STD_LOGIC_1164.all;
use ieee.NUMERIC_STD.all;

entity fa is
    Port ( A    : in  STD_LOGIC;
           B    : in  STD_LOGIC;
           Cin  : in  STD_LOGIC;
           S  : out  STD_LOGIC;
           tmp : out  STD_LOGIC
        );
end fa;

architecture sim of fa is
begin
    process(A, B, Cin)
    begin
        S <= A XOR B XOR Cin;
        tmp <= (A AND B) OR (Cin AND (A XOR B));
    end process;
end sim;

library ieee;
use ieee.STD_LOGIC_1164.all;
use ieee.NUMERIC_STD.all;

entity NA is
    Generic ( N : integer range 2 to 7 );
    Port ( A    : in  STD_LOGIC_VECTOR (N-1 downto 0);
           B    : in  STD_LOGIC_VECTOR (N-1 downto 0);
           Cin  : in  STD_LOGIC;
           S  : out  STD_LOGIC_VECTOR (N-1 downto 0);
           tmp : out  STD_LOGIC);
end NA;

architecture sim of NA is
    component fa is
        Port ( A : in  STD_LOGIC;
               B : in  STD_LOGIC;
               Cin : in  STD_LOGIC;
               S : out  STD_LOGIC;
               tmp : out  STD_LOGIC);
    end component;

    signal Ca_out : STD_LOGIC_VECTOR (N downto 0);
begin
    Ca_out(0) <= Cin;
    FA: for i in 0 to N-1 generate
        Adder_i: fa port map(A(i), B(i), Ca_out(i), S(i), Ca_out(i+1));
    end generate;
    tmp <= Ca_out(N);
end sim;

library ieee;
use ieee.STD_LOGIC_1164.all;
use ieee.NUMERIC_STD.all;

entity E1 is
    Generic ( N : integer range 1 to 8 );
    Port ( inp : in  STD_LOGIC_VECTOR (N-1 downto 0);
           outp : out  STD_LOGIC);
end E1;

architecture sim of E1 is
begin
    process(inp)
        variable Count : integer range 0 to N;
    begin
        Count := 0;
        for i in inp'range loop
            if inp(i) = '1' then
                Count := Count + 1;
            end if;
        end loop;
        
        if Count mod 2 = 0 then
            outp <= '1';
        else
            outp <= '0';
        end if;
    end process;
end sim;

library ieee;
use ieee.STD_LOGIC_1164.all;
use ieee.NUMERIC_STD.all;

entity OUTSIM is
    Generic ( N : integer range 1 to 8 );
    Port ( inp     : in  STD_LOGIC;
           ResultNOR : in  STD_LOGIC;
           S       : in  STD_LOGIC_VECTOR (N-1 downto 0);
           outp    : out  STD_LOGIC_VECTOR (N downto 0)
        );
end OUTSIM;

architecture sim of OUTSIM is
begin
    outp <= (ResultNOR & S);

    gen_extend_msb: if N > 8 generate
        outp(N) <= S(N-1);
    end generate gen_extend_msb;
    
end sim;


library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

entity MainComponent is
    Generic ( N : integer range 2 to 8 );
    Port ( A : in  STD_LOGIC_VECTOR (N-1 downto 0);
           B : in  STD_LOGIC_VECTOR (N-1 downto 0);
           C : out  STD_LOGIC_VECTOR (N downto 0)
        );
end MainComponent;

architecture sim of MainComponent is
    component NA is
        Generic ( N : integer range 2 to 8 );
        Port ( A    : in  STD_LOGIC_VECTOR (N-1 downto 0);
               B    : in  STD_LOGIC_VECTOR (N-1 downto 0);
               Cin  : in  STD_LOGIC;
               S  : out  STD_LOGIC_VECTOR (N-1 downto 0);
               tmp : out  STD_LOGIC
            );
    end component;

    component E1 is
        Generic ( N : integer range 1 to 8 );
        Port ( inp  : in  STD_LOGIC_VECTOR (N-1 downto 0);
               outp : out  STD_LOGIC
            );
    end component;

    component OUTSIM is
        Generic ( N : integer range 1 to 8 );
        Port ( inp     : in  STD_LOGIC;
               ResultNOR : in  STD_LOGIC;
               S       : in  STD_LOGIC_VECTOR (N-1 downto 0);
               outp    : out  STD_LOGIC_VECTOR (N downto 0)
            );
    end component;

    signal S : STD_LOGIC_VECTOR (N-1 downto 0);
    signal ResultNOR : STD_LOGIC;
begin
    Adder: NA generic map(N => N)
            port map(A => A, B => B, Cin => '0', S => S, tmp => open);

    Counter: E1 generic map(N => N)
            port map(inp => S, outp => ResultNOR);

    Generator: OUTSIM generic map(N => N)
                port map(inp => '1', ResultNOR => ResultNOR, S => S, outp => C);
end sim;
