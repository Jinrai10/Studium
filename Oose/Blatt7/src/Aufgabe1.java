import java.text.SimpleDateFormat;
import java.util.Random;

public class Aufgabe1 {
	public static void main(String[] args) {

	}
}

class ThreadTest {
	public static void main(String[] args) {
		Thread t1 = new Thread(new DateCommand());
		t1.start();
		Thread t2 = new Thread(new CounterCommand());
		t2.start();
	}
}

class DateCommand implements Runnable{

	@Override
	public void run() {
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		for(int i = 0;i<10;i++){
			System.out.println(df.format(System.currentTimeMillis()));
			try {
				Thread.sleep(new Random().nextInt(1000));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

class CounterCommand implements Runnable{

	@Override
	public void run() {
		for(int i = 0; i<10;i++){
			System.out.println("Counter: " + i);
			try {
				Thread.sleep(new Random().nextInt(1000));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}