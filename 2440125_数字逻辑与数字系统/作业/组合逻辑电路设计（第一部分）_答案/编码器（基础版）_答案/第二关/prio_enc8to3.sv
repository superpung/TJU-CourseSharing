`timescale 1ns/1ps

module prio_enc8to3 (

	input 		[7 : 0]	Din,
	input 			EN,
	output	logic 	[2 : 0]	Y,
	output 	logic		valid

	);

	always_comb begin

		if (!EN) {valid, Y} = 4'b0000;
		else if (Din[7]) {valid, Y} = 4'b1111;
		else if (Din[6]) {valid, Y} = 4'b1110;
		else if (Din[5]) {valid, Y} = 4'b1101;
		else if (Din[4]) {valid, Y} = 4'b1100;
		else if (Din[3]) {valid, Y} = 4'b1011;
		else if (Din[2]) {valid, Y} = 4'b1010;
		else if (Din[1]) {valid, Y} = 4'b1001;
		else if (Din[0]) {valid, Y} = 4'b1000;
		else 		 {valid, Y} = 4'b0000;

	end


endmodule
