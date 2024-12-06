# Custom-Reddit-Implementation

## Project Description

This project is an implementation of a simplified version of Reddit using C++. The data structures used include N-ary trees modeled as binary trees, lists, and queues, with a focus on object-oriented programming. The system allows managing posts and comments with complete functionalities for voting, sorting, and participation analysis.

## Features

### Post Management
- **Creating new posts**: Each post includes a title, username, creation date, and content.
- **Deleting posts**: Deleted posts automatically remove all associated comments.
- **Voting**: Posts can receive positive or negative votes, reflecting community feedback.

### Comment Management
- **Comments and replies**: Each post supports multiple comments, and each comment can be replied to an unlimited number of times.
- **Voting on comments**: Comments can also receive positive or negative votes.

### Reports and Visualization
- **Highlighted post**: Displays the most voted comment, the most active user, and the average rating of a post.
- **User contributions**: Lists all a user’s contributions across different posts, ordered chronologically.
- **Forum printing**: Allows printing all posts along with their comments and replies.

## Data Structures and Algorithms Used
- **N-ary trees modeled as binary trees**: A model is used that converts sibling nodes into consecutive children in a specific branch.
- **Data structures**: Lists, stacks, queues, and trees are fundamental to the implementation.
- **Efficient sorting**: Advanced sorting algorithms are employed, excluding the bubble sort algorithm.