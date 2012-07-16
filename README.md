arduino-wiegand
===============

Arduino library for communicating with Wiegand interface.

Wiegand interface operates through two wires (DATA0 and DATA1).

<table>
<thead><tr><th>Data 0</th><th>Data 1</th><th>Output</th></tr></thead>
<tbody>
<tr><td align=left>HIGH</td><td align=left>HIGH</td><td align=left>No data</td></tr>
<tr><td align=left>LOW</td><td align=left>HIGH</td><td align=left>0-bit</td></tr>
<tr><td align=left>HIGH</td><td align=left>LOW</td><td align=left>1-bit</td></tr>
<tr><td align=left>LOW</td><td align=left>LOW</td><td align=left>No data</td></tr>
</table>

It sends 26 bits in total, outputting a leading bit (even), 8 facility code bits, 16 card number bits and a trailing parity bit (odd).

 * site codes can be from 0 - 255.
 * serial number can be from 0 - 65535

Notice!
The library is untested. Use with caution.
