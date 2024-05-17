library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

package convolution_pkg is
    constant IMAGE_WIDTH : positive := 30;
    constant IMAGE_HEIGHT : positive := 30;
    constant FILTER_SIZE : positive := 3;
    type image_arr is array (natural range <>, natural range <>) of std_logic_vector(7 downto 0); 
    type filter_arr is array (natural range <>, natural range <>) of real; 
    type feature_map_arr is array (natural range <>, natural range <>) of std_logic_vector(7 downto 0);
    procedure convolution(input_image : in image_arr; filter : in filter_arr; num_units : in positive; output_fm : out feature_map_arr);
end package convolution_pkg;

package body convolution_pkg is
    procedure convolution(input_image : in image_arr; filter : in filter_arr; num_units : in positive; output_fm : out feature_map_arr) is
        variable result : real;       
    begin   
        for i in 0 to IMAGE_HEIGHT-FILTER_SIZE loop
            for j in 0 to (IMAGE_WIDTH-FILTER_SIZE) / num_units loop
                result := 0.0; 
				for num_unit in 0 to num_units loop
                for m in 0 to FILTER_SIZE-1 loop
                    for n in 0 to FILTER_SIZE-1 loop
                        result := result + real(to_integer(unsigned(input_image(i+m, j * num_unit +n)))) * filter(m, n);
                    end loop;
                end loop;
                result := result / 9.0;
                output_fm(i, j) := std_logic_vector(to_unsigned(integer(result), 8));
				end loop;
            end loop;
        end loop;        
    end convolution;
end convolution_pkg; 

library ieee;
use ieee.std_logic_1164.all;
use ieee.math_real.all;	 
use ieee.numeric_std.all;
use work.convolution_pkg.all;

entity q3 is  
	generic (
        number_of_units : positive := 14
    );
    port (
	input_image : in image_arr(0 to 29, 0 to 29);
	filter : in filter_arr(0 to 2, 0 to 2);
	output_image : out feature_map_arr(0 to 27, 0 to 27)
    );
end entity q3;

architecture Behavioral of q3 is
begin 
 	process(input_image, filter) is	   
	 variable out_matrix : feature_map_arr(0 to 27, 0 to 27);
    begin		
		convolution(input_image, filter, number_of_units, out_matrix);	
		output_image <= out_matrix;		
    end process;	
end Behavioral;