`timescale 1ns/1ps

module enc10to4_tb();

	logic	[9 : 0] I;
	logic	[3 : 0]	F;
	logic		valid;

	integer i;

	enc10to4 UDT(.I(I), .F(F), .valid(valid));

	initial begin
	
		for (i = 0; i < 1024; i = i + 1) begin

			I=i;
			#20;
			if(i%2 == 0) $display("At time %t: I = %b, F = %d, valid = %b", $time, I, F, valid);
			if(i == 1023) $display("At time %t: I = %b, F = %d, valid = %b", $time, I, F, valid);
			
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
	end

	initial begin

		$dumpfile("enc10to4.vcd");
		$dumpvars(0, enc10to4_tb);

	end		

endmodule
