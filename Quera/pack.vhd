library ieee;
use ieee.std_logic_1164.all;
use ieee.math_real.all;	 
use ieee.numeric_std.all;
use work.Q3_Pack.all;

entity result_for_convolve is  
	generic (
        n : positive := 14
    );
    port (
	img : in array1(0 to 29, 0 to 29);
	ftr : in array2(0 to 2, 0 to 2);
	oimg : out matrix_array(0 to 27, 0 to 27)
    );
end entity result_for_convolve;

Architecture conv of result_for_convolve is
begin 
 	process(img, ftr) is	   
	 variable res : matrix_array(0 to 27, 0 to 27);
    begin		
        convolve(img, ftr, n, res);	
		oimg <= res;		
    end process;	
end conv;

("11101110" , "11101110", "00011100" , "00110011" , "00001111" , "00011101" , "00001111" , "00001111" , "00001111" , "00110011" , "00001110" , "01110010" , "10001110" , "10001110" , "11011101" , "10011101" , "10001110" , "11001101" , "10110100" , "11011101" , "00111000" , "11101010" , "11100110" , "11101110", "11000101" , "1101100" , "00110010" , "00110001" , "10001011" , "11011011")