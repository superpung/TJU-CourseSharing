`timescale 1ns/1ps

module _74LS253(

	input		[3 : 0]	D1,
	input		[3 : 0] D2,
        input   		S0,
	input			S1,
	input 			G1_n,
	input 			G2_n,
	output	logic 		Y1,
	output  logic 		Y2

	);

	always @(*) begin

		if (G1_n) Y1 = 1'bz;
		else begin
			case({S1, S0})
				2'b00 : Y1 = D1[0];
				2'b01 : Y1 = D1[1];
				2'b10 : Y1 = D1[2];
				2'b11 : Y1 = D1[3];
			endcase
		end
	end

	always @(*) begin

		if (G2_n) Y2 = 1'bz;
		else begin
			case({S1, S0})
				2'b00 : Y2 = D2[0];
				2'b01 : Y2 = D2[1];
				2'b10 : Y2 = D2[2];
				2'b11 : Y2 = D2[3];
			endcase
		end
	end


endmodule
