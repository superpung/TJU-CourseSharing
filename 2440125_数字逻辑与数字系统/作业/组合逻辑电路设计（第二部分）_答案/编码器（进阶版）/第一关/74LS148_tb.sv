`timescale 1ns/1ps

module _74LS148_tb();

	logic	[7 : 0] I;
	logic		EN;
	logic	[2 : 0]	Q;
	logic		GS;
	logic		EO;

	integer i;

	_74LS148 UDT(.I(I), .EN(EN), .Q(Q), .GS(GS), .EO(EO));

	initial begin
	
		I = 8'b1111_1111;
		EN = 1'b1;
		#20;
		EN = 1'b0;
		#20;
		for (i = 0; i < 256; i++) begin
			I = i;
			#20;
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: EN = %b, I = %b, GS = %b, Q = %b, EO = %b", $time, EN, I, GS, Q, EO);
	end

	initial begin

		$dumpfile("74LS148.vcd");
		$dumpvars(0, _74LS148_tb);

	end		

endmodule
