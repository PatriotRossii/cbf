# Initialization

In C:

```
int i = 0;
char arr[30000];
memset(arr, 0, sizeof(arr))
```

LLVM IR equivalent:

```
@i = internal global i32 0
@arr = internal global [30000 x i8] zeroinitializer
```

# Next cell command (```>```)

In C:

```
i++;
```

LLVM IR equivalent:

```
%1 = load i32, i32* @i
%2 = add i32 %1, 1
store i32 %2, i32* @i
```

# Previous cell command (```<```)

In C:

```
i--;
```

LLVM IR equivalent:

```
%1 = load i32, i32* @i
%2 = sub i32 %1, 1
store i32 %2, i32* @i
```

# Increment current cell command (```+```)

In C:

```
arr[i]++;
```

LLVM IR equivalent:

```
%1 = load i32, i32* @i
%2 = getelementptr [30000 x i8], [30000 x i8]* @arr, i32 0, i32 %1
%3 = load i8, i8* %2
%4 = add i8 %3, 1
store i8 %4, i8* %2
```

# Decrement current cell command (```-```)

In C:

```
arr[i]--;
```

LLVM IR equivalent:

```
%1 = load i32, i32* @i
%2 = getelementptr [30000 x i8], [30000 x i8]* @arr, i32 0, i32 %1
%3 = load i8, i8* %2
%4 = sub i8 %3, 1
store i8 %4, i8* %2
```

# Print current cell command (```.```)

In C:

```
putchar(arr[i]);
```

LLVM IR equivalent:

```
%1 = load i32, i32* @i
%2 = getelementptr [30000 x i8], [30000 x i8]* @arr, i32 0, i32 %1
%3 = load i8, i8* %2
%4 = zext i8 %3 to i32
%5 = call i32 @putchar(i32 %4)
```

Before the main:

```
declare i32 @putchar(i32)
```

# Read current cell command (```,```)

In C:

```
arr[i] = getchar();
```

LLVM IR equivalent:

```
%1 = call i32 @getchar()
%2 = trunc i32 %1 to i8

%3 = load i32, i32* @i
%4 = getelementptr [30000 x i8], [30000 x i8]* @arr, i32 0, i32 %3

store i8 %2, i8* %4
```

Before the main:

```
declare i32 @getchar()
```

# Loop start command (```[```)

In C:

```
while(arr[i]) {
```

LLVM IR equivalent:

```
  br label %1
1:
  %2 = load i32, i32* @i
  %3 = getelementptr inbounds [30000 x i8], [30000 x i8]* @arr, i32 0, i32 %2
  %4 = load i8, i8* %3
  %5 = icmp ne i8 %4, 0
  br i1 %5, label %1, label %6
6:
	; Code next to the loop
```

# Loop end command (```]```)

In C:

```
}
```

LLVM IR equivalent

```
There are no need in equivalent
```