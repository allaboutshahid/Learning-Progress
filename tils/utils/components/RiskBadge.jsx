export default function RiskBadge({ level, color }) {
  return (
    <span style={{ background: color, padding: "4px 10px", borderRadius: "6px", color: "#0a0f1c", fontWeight: 600 }}>
      {level}
    </span>
  );
}