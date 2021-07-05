`timescale 1ns/1ps

module water_level(input en, input [3 : 0] wl, output logic [2 : 0] warn_led);

      always_comb begin
            if (en) begin
		  // warn_led从高位到低位对应红、黄、白灯
                  if (wl < 4'b1000) warn_led = 3'b000;  
                  else if ((wl >= 4'b1000) && (wl < 4'b1010)) warn_led = 3'b001;
                  else if ((wl >= 4'b1010) && (wl < 4'b1100)) warn_led = 3'b011;
                  else if ((wl >= 4'b1100) && (wl < 4'b1110)) warn_led = 3'b100;
                  else warn_led = 3'b000;
            end
            else warn_led = 3'b000;
      end

endmodule
