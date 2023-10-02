# Guidlines to Contribute
- First, select the correct category for your code.
  - General examples of algorithms or data structures should go in the Algorithms or DS folder.
  - Solutions to specific problems from a coding learning platform should go in the folder named after the platform, e.g. LeetCode.
  - If you are still unsure where your code should go, place it in the HelloWorld folder.
- Then, read the section below that corresponds to your chosen category.
- Finally, read your destination folder's README for further instruction.

## Category-specific Guidelines
### Algorithms & DS
- Put the code in correct language folder. 
- If the language folder is not there. then write file name as ```lang/file.lang```. This will automatically create new lang folder and put the file in that language's folder. 
  - For example ```Java/sieve.java```.

### Problem Solutions
- You can directly add the problem solutions to corresponding platform folder. File name should be the ID of the problem on particular platform.
- If platform folder doesn't exist then write file name as ```Platform/file.lang``` where ```Platform``` is the name of the platform and ```file.lang``` is the name of file.


## How to Contribute
1. **Fork the repository**

Click the "Fork" button at the top right of this repository to create a copy of it in your GitHub account.

2. **Clone the repository**

Clone the new, forked repository onto your local computer using Git.
```
git clone https://github.com/your-username/HacktoberfestForBeginners.git
cd HacktoberfestForBeginners
```

3. **Create a new branch**

Create a new branch to work on your contributions.
```
git checkout -b new-branch-name
```

4. **Make your contributions**

Add your contributions-- usually, a new file-- to the correct folder in the project.

5. **Commit your changes**

Commit your changes to the branch
```
git add .
git commit -m "Create a meaningful commit message"
```

6. **Push to your fork**

Push your local changes to your forked repository on GitHub.
```
git push -u origin new-branch-name
```

7. **Create a Pull Request**

On GitHub, go to your new branch on your forked repository. Select the button to open a new Pull Request, fill out the form, and submit!
