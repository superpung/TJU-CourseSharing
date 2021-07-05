`timescale 1ns/1ps

module mux8_4bits_tb();

	logic 	[3 : 0] D0, D1, D2, D3, D4, D5, D6, D7;
	logic 	[2 : 0] sel;
	logic 	[3 : 0]	Y;

	integer i;

	mux8_4bits DUT (
		.D0(D0),
		.D1(D1),
		.D2(D2),
		.D3(D3),
		.D4(D4),
		.D5(D5),
		.D6(D6),
		.D7(D7), 
		.sel(sel), 
		.Y(Y)
	);

	initial begin

		D0 = 4'b0000;
		D1 = 4'b0001;
		D2 = 4'b0010;
		D3 = 4'b0011;
		D4 = 4'b0100;
		D5 = 4'b0101;
		D6 = 4'b0110;
		D7 = 4'b0111;
		for(i = 0; i < 8; i = i+1) begin
			sel = i;
			#20;
		end
		D0 = 4'b1000;
		D1 = 4'b1001;
		D2 = 4'b1010;
		D3 = 4'b1011;
		D4 = 4'b1100;
		D5 = 4'b1101;
		D6 = 4'b1110;
		D7 = 4'b1111;
		for(i = 0; i < 8; i = i+1) begin
			sel = i;
			#20;
		end

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: sel = %b, Y = %d", $time, sel, Y);
	end

	initial begin

		$dumpfile("mux8_4bits.vcd");
		$dumpvars(0, mux8_4bits_tb);

	end

endmodule
