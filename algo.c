function get_next_line(fd):
    static remainder = NULL

    if fd < 0 or BUFFER_SIZE <= 0:
        return NULL

    // Step 1: Read data into a buffer
    while no newline found in remainder:
        bytes_read = read(fd, buffer, BUFFER_SIZE)
        if bytes_read == -1: // Error
            free remainder
            return NULL
        if bytes_read == 0: // EOF
            break
        buffer[bytes_read] = '\0'
        remainder = join_strings(remainder, buffer)

    // Step 2: Extract the line
    if newline exists in remainder:
        line = substring(remainder, up to newline)
        remainder = substring(remainder, after newline)
        return line
    else if remainder is not empty:
        // No newline, return the remainder
        line = remainder
        remainder = NULL
        return line

    return NULL // No more lines
