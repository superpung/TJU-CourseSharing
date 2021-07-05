`timescale 1ns/1ps

module dec4to16_tb();

	logic	[3 : 0] 	A;
	logic			en;
	logic	[15 : 0]	Y;

	integer i;

	dec4to16 UDT(.A(A), .en(en), .Y(Y));

	initial begin

		A  = 4'b0000;
		en = 1'b0;
		#20;
		en = 1'b1;
	
		for (i = 0; i < 16; i++) begin
			A = i;
			#20;
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: en = %b, A = %b, Y = %b", $time, en, A, Y);
	end

	initial begin

		$dumpfile("dec4to16.vcd");
		$dumpvars(0, dec4to16_tb);

	end		

endmodule
