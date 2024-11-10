This is a CLI tool to emulate the features of a blog.

## Usage

All the different features are available through a menu printed in the console, then the required information is asked directly via user input.  

### Troubleshooting

⚠️ In case of the following error:
>Unable to open directory: No such file or directory  
zsh: segmentation fault  ./.c-blog

It's required to manually create the directories used to store posts and comments, within the user's home directory (e.g. "/Users/ciro23" on macOS or "/home/ciro23" on Linux):
```
.c-blog/
├── posts/
└── comments/
```

## Features

1. Create a post
2. Add a comment to a post
3. View a post and all its comments
4. List all posts

## Support

It's currently supported on Unix-based systems only, and it was tested on Linux and macOS.  
This project is not perfect as it may crash sometimes :/
