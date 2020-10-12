import java.util.Scanner;

class Student {

	private int id;
	private String fname;
	private double cgpa;

	public Student(int id, String fname, double cgpa) {
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}

	public int getId() {
		return id;
	}

	public String getFname() {
		return fname;
	}

	public double getCgpa() {
		return cgpa;
	}

}


class Solution {

    /* Class variable for comparing students */
    static final Comparator<Student> CGPA_ORDER = new Comparator<Student>() {
        /*
         * Compares two students based on CGPA first (in descending order),
         * then on first name (in alphabetical order), then on ID (in numerical
         * order).
         */
        public int compare(Student a, Student b) {
            int cgpaCompare = Double.compare(a.getCgpa(), b.getCgpa());

            if (cgpaCompare != 0) {
                return -cgpaCompare; // negative => descending order
            }

            int nameCompare = a.getFname().compareTo(b.getFname());

            if (nameCompare != 0) {
                return nameCompare;
            }

            int idCompare = Integer.compare(a.getId(), b.getId());

            return idCompare;
        }
    };

	public static void main(String[] args) {
        /* Read in all students and create a list of Student objects */
        Scanner in = new Scanner(System.in);
		int numStudents = Integer.parseInt(in.nextLine());
		List<Student> studentList = new ArrayList<>();
		for (int i = 0; i < numStudents; i++) {
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();

			Student student = new Student(id, fname, cgpa);
			studentList.add(student);
		}
        in.close();

        /* Sort and print students */
        studentList.sort(CGPA_ORDER);
      	for (Student student: studentList) {
			System.out.println(student.getFname());
		}
	}

}
