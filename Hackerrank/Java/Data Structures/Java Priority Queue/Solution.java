import java.util.PriorityQueue;
import java.util.Comparator;

class Student {

    private int id;
    private String name;
    private double cgpa;

    Student(int id, String name, double cgpa) {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }

    int getId() {
        return id;
    }

    String getName() {
        return name;
    }

    double getCGPA() {
        return cgpa;
    }

}


class Priorities {

    List<Student> getStudents(List<String> events) {

        /* Instantiate a priority queue with a custom comparator to order students */
        PriorityQueue<Student> queue = new PriorityQueue(new Comparator<Student>() {
            public int compare(Student s1, Student s2) {
                // sort on CGPAs (descending) first
                int cgpaDiff = Double.compare(s2.getCGPA(), s1.getCGPA());
                if (cgpaDiff != 0) return cgpaDiff;

                // sort alphabetically on names second (case-sensitive)
                int nameDiff = (s1.getName()).compareTo(s2.getName());
                if (nameDiff != 0) return nameDiff;

                // sort on IDs (ascending) last
                return Integer.compare(s1.getId(), s2.getId());
            }
        });

        /* Process all queueing events */
        for (String event : events) {
            String[] tokens = event.split(" ");

            if (tokens[0].equals("ENTER")) {
                Student student = new Student(Integer.parseInt(tokens[3]),    // id
                                              tokens[1],                      // name
                                              Double.parseDouble(tokens[2])); // cgpa

                queue.add(student);
            } else if (tokens[0].equals("SERVED")) {
                queue.poll();
            }
        }

        /* Build a list of students still in the queue, in priority order */
        List<Student> list = new ArrayList<>();

        while (queue.size() > 0) {
            list.add(queue.poll());
        }

        return list;
    }

}
