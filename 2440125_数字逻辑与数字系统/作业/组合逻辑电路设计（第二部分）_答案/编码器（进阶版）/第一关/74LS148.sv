`timescale 1ns/1ps

module _74LS148(

	input		[7 : 0]	I,
	input 			EN,

	output	logic	[2 : 0] Q,
	output 	logic		GS,
	output 	logic		EO

	);

	always @(*) begin

		if (EN) {EO, GS, Q} = 5'b11_111;
		else if (I == 8'b1111_1111) {EO, GS, Q} = 5'b01_111;
		else if (!I[7]) {EO, GS, Q} = 5'b10_000;
		else if (!I[6]) {EO, GS, Q} = 5'b10_001;
		else if (!I[5]) {EO, GS, Q} = 5'b10_010;
		else if (!I[4]) {EO, GS, Q} = 5'b10_011;
		else if (!I[3]) {EO, GS, Q} = 5'b10_100;
		else if (!I[2]) {EO, GS, Q} = 5'b10_101;
		else if (!I[1]) {EO, GS, Q} = 5'b10_110;
		else if (!I[0]) {EO, GS, Q} = 5'b10_111;
		else		{EO, GS, Q} = 5'b01_111;

	end

endmodule
