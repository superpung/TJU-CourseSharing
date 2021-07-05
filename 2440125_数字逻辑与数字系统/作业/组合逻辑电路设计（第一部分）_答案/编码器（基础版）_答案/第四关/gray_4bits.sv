`timescale 1ns/1ps

module gray_4bits (

	input 		[3 : 0]	Din,
	input 			EN,
	input 			gray_n,
	output	logic 	[3 : 0]	Dout,
	output 	logic		valid

	);

	integer i;

	always_comb begin

		if (!EN) {valid, Dout} = 5'b0_0000;
		else begin
		
			if (!gray_n) begin

				Dout[3]		= Din[3];
				Dout[2 : 0]	= Din[3 : 1] ^ Din[2 : 0];
				valid = 1'b1;

			end
			else begin

				Dout[3]		= Din[3];
		//	    Dout[2:0]=Dout[3:0]^Din[2:0];//这个为啥不行?可不可能是从低位开始异或
				for (i = 2; i >= 0; i = i - 1)
					Dout[i] = Dout[i + 1] ^ Din[i];
				valid = 1'b1;
				
			end

		end

	end


endmodule
