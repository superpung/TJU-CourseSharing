`timescale 1ns/1ps

module fulladder_tb();

	logic A, B, Cin;
	logic Sum, Cout;

	integer i;

	fulladder DUT(.A(A), .B(B), .Cin(Cin), .Sum(Sum), .Cout(Cout));

	initial begin

		for(i = 0; i < 8; i = i+1) begin
			
			{B, A, Cin} = i;
			#20;

		end

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: B = %b, A = %b, Cin = %b, Cout = %b, Sum = %b", $time, B, A, Cin, Cout, Sum);
	end

	initial begin
		
		$dumpfile("fulladder.vcd");
		$dumpvars(0, fulladder_tb);

	end

endmodule
