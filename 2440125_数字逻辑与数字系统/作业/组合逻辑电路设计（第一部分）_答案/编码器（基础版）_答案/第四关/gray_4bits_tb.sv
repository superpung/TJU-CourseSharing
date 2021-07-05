`timescale 1ns/1ps

module gray_4bits_tb();

	logic	[3 : 0] Din;
	logic		EN;
	logic 		gray_n;
	logic	[3 : 0]	Dout;
	logic		valid;

	integer i;

	gray_4bits UDT(.Din(Din), .EN(EN), .gray_n(gray_n), .Dout(Dout), .valid(valid));

	initial begin
		
		$display("Binary to Gray:");
		Din = 4'b0000;
		gray_n = 1'b0;
		EN = 1'b0;
		#20;
		EN = 1'b1;
		for (i = 0; i < 16; i++) begin
			Din = i;
			#20;
		end

		$display("\nGray to Binary:");
		EN = 1'b0;
		gray_n = 1'b1;
		Din = 4'b0000;
		#20;
		EN = 1'b1;
		#20;
		Din = 4'b0001;
		#20;
		Din = 4'b0011;
		#20;
		Din = 4'b0010;
		#20;
		Din = 4'b0110;
		#20;
		Din = 4'b0111;
		#20;
		Din = 4'b0101;
		#20;
		Din = 4'b0100;
		#20;
		Din = 4'b1100;
		#20;
		Din = 4'b1101;
		#20;
		Din = 4'b1111;
		#20;
		Din = 4'b1110;
		#20;
		Din = 4'b1010;
		#20;
		Din = 4'b1011;
		#20;
		Din = 4'b1001;
		#20;
		Din = 4'b1000;
		#20;
		$finish;

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: EN = %b, gray_n = %b, Din = %b, Dout = %b, valid = %b", $time, EN, gray_n, Din, Dout, valid);
	end

	initial begin

		$dumpfile("gray_4bits.vcd");
		$dumpvars(0, gray_4bits_tb);

	end		

endmodule
