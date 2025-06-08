Paragraph:

You are building a component for a sensor system.
The sensors report floating-point values (e.g. temperature, pressure, voltage, etc.) at irregular intervals.
You are asked to implement a moving average calculator module that can process a stream of such sensor values and compute the moving average of the last N values.

The module must allow you to:

    Set the window size N at creation time.

    Feed new sensor values in one by one.

    Query the current moving average at any time.

    The moving average is undefined until at least one value is present.

Example:

Window size = 3  
feed(10.0) → average = 10.0  
feed(20.0) → average = 15.0  
feed(30.0) → average = 20.0  
feed(40.0) → average = 30.0 (last 3 values are [20, 30, 40])  

Clarifications:

    You do not need to handle multiple sensors — just one stream of values.

    You must make your module clean and reusable (not just "hack it in main").

    The module should encapsulate internal state properly.

    Use modern C++ where it makes sense.
