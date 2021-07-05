`timescale 1ns/1ps

module dec3to8_tb();

	logic	[2 : 0] Din;
	logic		en;
	logic	[7 : 0]	Y;

	integer i;

	dec3to8 UDT(.Din(Din), .en(en), .Y(Y));

	initial begin
	
		Din = 3'b000;
		en = 1'b0;
		#20;
		en = 1'b1;
		for (i = 0; i < 7; i++) begin
			#20;
			Din = Din + 1;
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: en = %b, Din = %b, Y = %b", $time, en, Din, Y);
	end

	initial begin

		$dumpfile("dec3to8.vcd");
		$dumpvars(0, dec3to8_tb);

	end		

endmodule
