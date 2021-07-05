`timescale 1ns/1ps

module bin2bcd_4bits_tb();

	logic	[3 : 0] bin;
	logic		EN;
	logic	[4 : 0]	bcd;
	logic		valid;

	integer i;

	bin2bcd_4bits UDT(.bin(bin), .EN(EN), .bcd(bcd), .valid(valid));

	initial begin
	
		bin = 4'b0000;
		EN = 1'b0;
		#20;
		EN = 1'b1;
		for (i = 0; i < 16; i++) begin
			bin = i;
			#20;
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: EN = %b, bin = %b, bcd = %b, valid = %b", $time, EN, bin, bcd, valid);
	end

	initial begin

		$dumpfile("bin2bcd_4bits.vcd");
		$dumpvars(0, bin2bcd_4bits_tb);

	end		

endmodule
