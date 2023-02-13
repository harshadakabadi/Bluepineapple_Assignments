
    class Node {
        constructor(bookTitle, author, publicationDate) {
          this.bookTitle = bookTitle;
          this.author = author;
          this.publicationDate = publicationDate;
          this.next = null;
        }
      }
      
      class LinkedList {
        constructor() {
          this.head = null;
        }
      
        add(bookTitle, author, publicationDate) {
          let newNode = new Node(bookTitle, author, publicationDate);
          if (!this.head) {
            this.head = newNode;
          } else {
            let current = this.head;
            while (current.next) {
              current = current.next;
            }
            current.next = newNode;
          }
        }
      
        delete(bookTitle) {
          if (!this.head) {
            return;
          }
          if (this.head.bookTitle === bookTitle) {
            this.head = this.head.next;
          } else {
            let current = this.head;
            while (current.next && current.next.bookTitle !== bookTitle) {
              current = current.next;
            }
            if (current.next) {
              current.next = current.next.next;
            }
          }
        }
      
        search(bookTitle) {
          if (!this.head) {
            return null;
          }
          let current = this.head;
          while (current) {
            if (current.bookTitle === bookTitle) {
              return current;
            }
            current = current.next;
          }
          return null;
        }
      
        display() {
          let current = this.head;
          while (current) {
            console.log(`Book Title: ${current.bookTitle} | Author: ${current.author} | Publication Date: ${current.publicationDate}`);
            current = current.next;
          }
        }
      }
      
      let bookList = new LinkedList();
      
      bookList.add("To Kill a Mockingbird", "Harper Lee", "July 11, 1960");
      bookList.add("The Great Gatsby", "F. Scott Fitzgerald", "April 10, 1925");
      bookList.add("Pride and Prejudice", "Jane Austen", "January 28, 1813");
      
      bookList.display();
      
      bookList.delete("Pride and Prejudice");
      
      console.log("After deleting a book:");
      bookList.display();
      
      let foundBook = bookList.search("The Great Gatsby");
      console.log(foundBook);


  
