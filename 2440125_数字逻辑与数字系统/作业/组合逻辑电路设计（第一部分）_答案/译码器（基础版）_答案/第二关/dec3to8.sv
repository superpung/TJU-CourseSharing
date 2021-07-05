`timescale 1ns/1ps

module dec3to8 (

	input 		[2 : 0]	Din,
	input 			en,
	output	logic 	[7 : 0]	Y

	);

	integer i;
	
	always_comb begin

		if (!en) Y = 8'b0000_0000;
		else begin
		
			for(i = 0; i < 8; i = i + 1) begin
			
				if (Din == i)
					Y[i] = 1;
				else
					Y[i] = 0;
			
			end

		end

	end


endmodule
