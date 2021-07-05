`timescale 1ns/1ps

module enc8to3_tb();

	logic	[7 : 0] Din;
	logic		EN;
	logic	[2 : 0]	Y;
	logic		valid;

	integer i;

	enc8to3 UDT(.Din(Din), .EN(EN), .Y(Y), .valid(valid));

	initial begin
	
		Din = 8'b0000_0000;
		EN = 1'b0;
		#20;
		EN = 1'b1;
		for (i = 0; i < 256; i++) begin
			Din = i;
			#20;
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: EN = %b, Din = %b, Y = %b, valid = %b", $time, EN, Din, Y, valid);
	end

	initial begin

		$dumpfile("enc8to3.vcd");
		$dumpvars(0, enc8to3_tb);

	end		

endmodule
