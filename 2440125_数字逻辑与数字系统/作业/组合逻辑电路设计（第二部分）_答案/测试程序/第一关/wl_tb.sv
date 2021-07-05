`timescale 1ns/1ps

module water_level_tb();

	logic 		en;
	logic [3 : 0] 	wl;
	logic [2 : 0] 	warn_led;

	int i;

	water_level DUT(.en(en), .wl(wl), .warn_led(warn_led));

	initial begin
		en = 1'b0;
		wl = 0;
		#20;
		en = 1'b1;
		for(i = 0; i < 14; i++) begin
			wl = i;
			#20;
		end

	end

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: en = %b, wl = %d, warn_led = %b", $time, en, wl, warn_led);
	end

	initial begin

		$dumpfile("wl.vcd");
		$dumpvars(0, water_level_tb);

	end

endmodule
