`timescale 1ns/1ps

module enc8to3 (

	input 		[7 : 0]	Din,
	input 			EN,
	output	logic 	[2 : 0]	Y,
	output 	logic		valid

	);

	always_comb begin

		if (!EN) {valid, Y} = 4'b0000;
		else begin
		
			case(Din)
			
				8'b0000_0001 : {valid, Y} = 4'b1000;
				8'b0000_0010 : {valid, Y} = 4'b1001;
				8'b0000_0100 : {valid, Y} = 4'b1010;
				8'b0000_1000 : {valid, Y} = 4'b1011;
				8'b0001_0000 : {valid, Y} = 4'b1100;
				8'b0010_0000 : {valid, Y} = 4'b1101;
				8'b0100_0000 : {valid, Y} = 4'b1110;
				8'b1000_0000 : {valid, Y} = 4'b1111;
				default	     : {valid, Y} = 4'b0000;

			endcase

		end

	end


endmodule
