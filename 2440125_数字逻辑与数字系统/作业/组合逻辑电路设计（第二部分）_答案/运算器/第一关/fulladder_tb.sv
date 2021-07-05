`timescale 1ns/1ps

module fulladder_tb();

	logic A, B, Cin;
	logic S, Cout;

	integer i;

	fulladder DUT(.A(A), .B(B), .Cin(Cin), .S(S), .Cout(Cout));

	initial begin

		for(i = 0; i < 8; i = i+1) begin
			
			{A, B, Cin} = i;
			#20;

		end

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: A = %b, B = %b, Cin = %b, Cout = %b, S = %b", $time, A, B, Cin, Cout, S);
	end

	initial begin
		
		$dumpfile("fulladder.vcd");
		$dumpvars(0, fulladder_tb);

	end

endmodule
