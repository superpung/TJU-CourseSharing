package com.huawei.classroom.student.h16;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class MyServer extends Thread {
	private int port;

	public void startListen(int port) {
		this.port = port;
		this.start();
	}

	public void run() {
		Socket socket = null;
		PrintWriter out = null;
		BufferedReader in = null;

		try {
			ServerSocket server = new ServerSocket(port);
			socket = server.accept(); // 等待客户端连接，注意这种方式，可以和多个客户端建立连接
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new java.io.PrintWriter(socket.getOutputStream());
			String line = in.readLine();
			while (!"bye".equals(line)) {
				out.write(line + "\r\n");
				out.flush();
				line = in.readLine();
			}
			in.close();
			out.close();
			socket.close();

		} catch (IOException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		} finally {

		}
	}

	public static void close(Closeable inout) {
		if (inout != null) {
			try {
				inout.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
