`timescale 1ns/1ps

module comp_4bits_tb();

	logic [3 : 0] 	A, B;
	logic 		EQ;

	integer i, j;

	comp_4bits DUT(.A(A), .B(B), .EQ(EQ));

	initial begin


		for(i = 0; i < 16; i = i + 1) begin
			for(j = 0; j < 16; j = j + 1) begin
				A = i;
				B = j;
				#20;
			end
		end

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: A = %d, B = %d, EQ = %b", $time, A, B, EQ);
	end

	initial begin
		
		$dumpfile("comp_4bits.vcd");
		$dumpvars(0, comp_4bits_tb);

	end

endmodule
