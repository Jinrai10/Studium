import java.io.File;

public class Aufgabe2 {
	public static void main(String[] args){
		Thread t = new Thread(new DateiBeobachter("Blatt7/text.txt"));
		t.start();
	}
}

class DateiBeobachter implements Runnable{
	File file;
	long lastmod;


	public DateiBeobachter(File f) {
		file = f;
		lastmod = file.lastModified();
	}

	public DateiBeobachter(String str) {
		file = new File(str);
		lastmod = file.lastModified();
	}

	@Override
	public void run() {
		while(true) {
			if(lastmod != file.lastModified()){
				System.out.printf("The file [%s] has been modified. %n", file.getName());
				lastmod = file.lastModified();
			}
			System.out.println(file.getName());
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

		}
	}
}