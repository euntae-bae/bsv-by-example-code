// Standard connectivity interfaces
package Tb;
import FIFO::*;
import GetPut::*;
import ClientServer::*;
import Connectable::*;

(* synthesize *)
module mkTb (Empty);
    Client#(int, int) stimulus_gen  <- mkStimulusGen;
    Server#(int, int) dut           <- mkDut;
    
    // Connect a client to a server (flow of requests and flow of responses)
    mkConnection(stimulus_gen, dut);
endmodule

/*
interface Client#(type req_type, type resp_type);
    interface Get#(req_type) request;
    interface Put#(resp_type) response;
endinterface

interface Server#(type req_type, type resp_type);
    interface Put#(req_type) request;
    interface Get#(resp_type) response;
endinterface
*/

// The DUT
(* synthesize *)
module mkDut (Server#(int, int));
    FIFO#(int) f_in     <- mkFIFO;  // to buffer incoming requests
    FIFO#(int) f_out    <- mkFIFO;  // to buffer outgoing responses

    rule compute;
        let x = f_in.first;
        f_in.deq;
        let y = x + 1;              // Some 'server' computation 
        if (x == 20)                // Modeling an 'occasional bug'
            y = y + 1;
        f_out.enq(y);
    endrule

    interface request = toPut(f_in);
    interface response = toGet(f_out);
endmodule

// interface는 1급 객체다. function을 통해 반환 가능
// toPut, toGet

// The stimulus generator
(* synthesize *)
module mkStimulusGen (Client#(int, int));
    Reg#(int) x             <- mkReg(0);    // Seed for stimulus
    FIFO#(int) f_out        <- mkFIFO;      // To buffer outgoing requests
    FIFO#(int) f_in         <- mkFIFO;      // To buffer incoming responses
    FIFO#(int) f_expected   <- mkFIFO;      // To buffer expected responses

    rule gen_stimulus;
        f_out.enq(x);
        x <= x + 10;
        f_expected.enq(x + 1);
    endrule

    rule check_results;
        let y = f_in.first;
        f_in.deq;
        let y_exp = f_expected.first;
        f_expected.deq;
        $write("(y, y_expected) = (%0d, %0d)", y, y_exp);
        if (y == y_exp)
            $display(": PASSED");
        else
            $display(": FAILED");
        if (y_exp > 50)
            $finish;
    endrule

    interface request = toGet(f_out);
    interface response = toPut(f_in);
endmodule

endpackage